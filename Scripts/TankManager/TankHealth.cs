using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TankHealth : MonoBehaviour {

    public float hp = 100;
    public Slider hpSlider;
    public GameObject tankExplosion;
   // public AudioClip TankDamageAudio;   
    //private Transform audioPosition;//播放位置
    public void OnCollisionEnter( Collision col ) {
        if (col.gameObject.tag == "Walls" || col.gameObject.tag == "Tank") {
            RushDamage();
        }
    }
    
	// Use this for initialization
	void Start () {
	    SetHealth(hp);
       // Jcount = this.gameObject.GetComponent<Tank>().counts;
	}
    private void SetHealth(float HP)
    {
        hpSlider.value = HP/100;
    }
    public void ResetHealth()
    {
        hp = 100;
        hpSlider.value = hp/100;
    }
	// Update is called once per frame
    public void RushDamage()
    {
        hp -= Random.Range(2,7);
        SetHealth(hp);
        if(hp<=0)
        {
            OnDeath();
            hp = 0;
        }
    }
    public void TakeDamage() {
        hp -= Random.Range(10, 20);
        SetHealth(hp);
        if(hp <= 0)
        {
            OnDeath();
            hp = 0;
        }
    }   
    public void OnDeath()
    {    
        GameObject tankExplosionInstance = Instantiate(tankExplosion);
        tankExplosionInstance.transform.position = transform.position;
        Destroy(tankExplosionInstance);
        gameObject.SetActive(false);
    }
    public void TakeRedDamage()
    {
        hp -= Random.Range(30,40);
        SetHealth(hp);
        if(hp <= 0)
        {
            OnDeath();
            hp = 0;
        }
    }
}
