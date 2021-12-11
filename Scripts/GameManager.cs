using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class GameManager : MonoBehaviour
{
   [SerializeField]
   private Tank []tanks;
   [SerializeField]
   private GameObject TankPrefab;
   [SerializeField]
   private FollowTarget FollowTarget;
   private TankManager tankManager;
   void Start()
   {
       spawnTanks();
       initCamera();
   }
   private void spawnTanks()
   {
       tankManager = new TankManager();

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
