using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class TankAttack : MonoBehaviour {

    [SerializeField]
	private GameObject shellPrefab;
	[SerializeField]
	private GameObject RedShellPrefab;
	[SerializeField]
    private Transform firePoint;
	[SerializeField]
	private float fireForce = 10;
	[SerializeField]
	private int playerNumber = 1;
	[SerializeField]
	private float minForce = 7;
	[SerializeField]
	private float maxForce = 20;
	public float forceLoadingTime = 0.7f;
	[SerializeField]
	private float CDtime = 0;
	public Slider AimSlider;
	//public AudioClip FireAudio;
	//private int ShellValue;
	void Start()
	{
	//	ShellValue = this.gameObject.ShellValue;
	}
	void Update () {
		CDtime += Time.deltaTime ;
		if(CDtime >0.2f)
		{
			if (Input.GetButtonDown("Fire"+ playerNumber)) {
	       //fire();
			fireForce = minForce;
	    	}
			else if(Input.GetButton("Fire"+ playerNumber)) {
			fireForce += Time.deltaTime * (maxForce - minForce)/forceLoadingTime;
			}
			else if(Input.GetButtonUp("Fire"+playerNumber)) {
				if(fireForce > maxForce)
				{
					fireForce = maxForce;
					RedFire();
				}
				else 
				{
					Fire();
				}
				CDtime = 0;
				fireForce = minForce;
			}
		}
		SetAimSlider();
	}

	private void Fire()
	{
		GameObject shell = GameObject.Instantiate(shellPrefab,firePoint.position,firePoint.rotation) as GameObject;
		Rigidbody rb = shell.GetComponent<Rigidbody>();			
		rb.velocity = firePoint.forward * fireForce;
	}
	private void RedFire()
	{
		GameObject redshell = GameObject.Instantiate(RedShellPrefab,firePoint.position,firePoint.rotation) as GameObject;
		Rigidbody rrb = redshell.GetComponent<Rigidbody>();
		rrb.velocity = firePoint.forward * fireForce;
	}
	public void SetPlayerNumber(int playerNumber)
    {
        this.playerNumber = playerNumber;
    }
	private void SetAimSlider()
	{
		float value = (fireForce - minForce) / (maxForce - minForce);
		AimSlider.value = value;
	}
}
