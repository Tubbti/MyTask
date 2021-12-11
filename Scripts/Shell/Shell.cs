using UnityEngine;
using System.Collections;

public class Shell : MonoBehaviour {

    public float maxLifeTime = 2;
    
    public GameObject shellExplosionPrefab;

    void Start ()
    {   
        Destroy(gameObject,maxLifeTime);
    }
    private void OnTriggerEnter( Collider collider) {
        GameObject.Instantiate(shellExplosionPrefab, transform.position, transform.rotation); 
        if (collider.tag == "Tank") {
            collider.SendMessage("TakeDamage");
        }
        Destroy(gameObject);
    }

}
