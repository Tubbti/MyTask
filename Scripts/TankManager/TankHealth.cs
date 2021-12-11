using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TankHealth : MonoBehaviour {

    public int hp = 120;
    private int hpTotal;
    public Slider hpSlider;
    public GameObject tankExplosion;
    public int GGflag = 0;
    private int Jcount;
   // public AudioClip TankDamageAudio;   
    //private Transform audioPosition;//播放位置
    public void OnCollisionEnter( Collision col ) {
        if (col.gameObject.tag == "Walls" || col.gameObject.tag == "Tank") {
            TakeDamage();
        }
    }
    
	// Use this for initialization
	void Start () {
	    hpTotal = hp;
        Jcount = this.gameObject.GetComponent<Tank>().counts;
	}
	
	// Update is called once per frame
    public void TakeDamage() {
        if (hp <= 0) return;
        hp -= Random.Range(10, 20);
        hpSlider.value = (float)hp /hpTotal;
        if (hp <= 0) {
            GameObject.Instantiate(tankExplosion, transform.position + Vector3.up, transform.rotation);
            GameObject.Destroy(this.gameObject);
            Jcount--;
            Invoke("ReloadScene",4);
        }
    }
    public void TakeRedDamage()
    {
        if (hp <= 0) return;
        hp -= Random.Range(30, 40);
        hpSlider.value = (float)hp /hpTotal;
        if (hp <= 0) {
            GameObject.Instantiate(tankExplosion, transform.position + Vector3.up, transform.rotation);
            GameObject.Destroy(this.gameObject);
            Jcount--;
            Invoke("ReloadScene",4);
        }
    }
    public void ReloadScene()
    {
        SceneManager.LoadScene("Main");
    }
}
