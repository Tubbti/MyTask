using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class GameManager : MonoBehaviour
{
   public Tank []tanks;
   [SerializeField]
   private GameObject TankPrefab;
   [SerializeField]
   private FollowTarget FollowTarget;
   [SerializeField]
   private Text messageText;
   private TankManager tankManager;
   public int gameRoundCount = 2;

   void Start()
   {
       spawnTanks();
       initCamera();
       StartCoroutine(GameLoop());
   }
   private IEnumerator GameLoop()
   {
       yield return StartCoroutine(RoundStart());
       yield return StartCoroutine(RoundPlaying());
       yield return StartCoroutine(RoundEnd());

   }
   private IEnumerator RoundStart()
   {
       messageText.text = "Game Start";
       tankManager.ResetTanks();
       tankManager.EnableTanks(false);
       yield return new WaitForSeconds(2);
   }
    private IEnumerator RoundPlaying()
   {
       messageText.text = "";
       tankManager.EnableTanks(true);
       yield return new WaitUntil(tankManager.IsOneTankLeft);
   }
    private IEnumerator RoundEnd()
   {
       messageText.text = "Round Over";
       tankManager.EnableTanks(false);
       Tank roundWinner = tankManager.GetRoundWinner();
       roundWinner.IncreaseRoundWinnerCount();
       
       Tank gameWinner = tankManager.GetGameWinner();
       if(gameWinner != null)
       {
           messageText.text = "Game Over\n";
       }
       else
       {
           messageText.text = "Next Round";
           yield return new WaitForSeconds(3);
           StartCoroutine(GameLoop());
       }
       
   }
   private void spawnTanks()
   {
       tankManager = new TankManager(gameRoundCount);

       for(int i=0;i<tanks.Length;i++)
       {
           Tank tank = tanks[i];
           GameObject tankGameObject = Instantiate(TankPrefab,tank.spawnPoint.position,Quaternion.identity);
           tank.Setup(tankGameObject,i+1);
            tankManager.AddTank(tank);
       }
   }
   private void initCamera()
   {
       Transform[] targets = tankManager.GetTanksTransforms();
       FollowTarget.SetTanksTransforms(targets);
   }
    
   
}
