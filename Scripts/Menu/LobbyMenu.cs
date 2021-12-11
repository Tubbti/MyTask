using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LobbyMenu : MonoBehaviour
{
    // Start is called before the first frame update
    
    public GameObject BottonPlay;
    public GameObject BottonQuit;
    public GameObject Camera;
   

    // Update is called once per frame
    void Update()
    {
        Camera.transform.Rotate(new Vector3(0,0.2f,0),Space.Self);
    }
    void Start()
    {
        BottonPlay.GetComponent<Button>().onClick.AddListener(_Play);
        BottonQuit.GetComponent<Button>().onClick.AddListener(_Quit);
    }
    void _Play()
    {
        SceneManager.LoadScene("Main");
    }
    void _Quit()
    {
        //#if UNITY_EDITOR
        //    UnityEditor.EditorApplication.isPlaying = false;
        //#else
            Application.Quit();
        //#endif
    }
}