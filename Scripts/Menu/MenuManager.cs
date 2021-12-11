using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MenuManager : MonoBehaviour
{
    public GameObject BottonPauseMenu;
    public GameObject BottonReload;
    public GameObject BottonExit;
    public Text TextClock;
    public Text TextCount;
    private float m_Timer;
    private int m_Minute;
    private int m_Second;
    private bool flag = false;
    public int count{
           get{
               return count;
           }
           set{
               SetCountText();
               Invoke("OffCountText",4);
           }
    }
    void Start()
    {
        TextCount.text = ("Game Start\n" +"0 : 0"); 
        Invoke("OffCountText",4);
        count = 2-this.gameObject.GetComponent<Tank>().counts;
        BottonPauseMenu.SetActive(false);
        BottonReload.GetComponent<Button>().onClick.AddListener(OnReload);
        BottonExit.GetComponent<Button>().onClick.AddListener(OnExit);
    }
    void Update()
    {
        m_Timer += Time.deltaTime;
        m_Second = (int)m_Timer;
        if(m_Second > 59.0f)
        {
            m_Second = (int)(m_Timer - (m_Minute * 60));
        }
        m_Minute = (int)m_Timer/60;
        TextClock.text = string.Format("{0:d2}:{1:d2}",m_Minute,m_Second); 
        
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            if(!flag)
            {
                OnPause();
            }
            else {
                OnReload();
            }
        }
    }

    public void OnPause()
    {
        Time.timeScale = 0;
        BottonPauseMenu.SetActive(true);
        flag = true;
    }

    public void OnReload()
    {
        Time.timeScale = 1f;
        BottonPauseMenu.SetActive(false);
        flag = false;
    }
  
    public void OnExit()
    {
        Application.Quit();
    }
    public void SetCountText()
    {
        TextCount.text = count.ToString() + " : " + count.ToString();
     //   TextCount.SetActive(true);
    }
    public void OffCountText()
    {
      //  TextCount.SetActive(false);
    }
}
