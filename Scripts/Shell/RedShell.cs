using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RedShell : MonoBehaviour
{
    public float maxLifeTime = 3;
    
    public GameObject shellExplosionPrefab;

    void Start ()
    {   
        Destroy(gameObject,maxLifeTime);
    }
    private void OnTriggerEnter( Collider collider) {
        GameObject.Instantiate(shellExplosionPrefab, transform.position, transform.rotation); 
        if (collider.tag == "Tank") {
            collider.SendMessage("TakeRedDamage");
        }
        Destroy(gameObject);
    }

}
