using UnityEngine;
using System.Collections;
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
	private int ShellValue;
	void Start()
	{
		ShellValue = this.gameObject.GetComponent<Tank>().ShellValue;
	}
	void Update () {
	    if(Input.GetButtonDown("ChangeShell"+playerNumber)) 
		{
			if(ShellValue == 1) ShellValue = 2;
			else ShellValue = 1;
		}
		CDtime += Time.deltaTime ;
		if(CDtime >0.2f&&ShellValue == 1)
		{
			if(Input.GetButtonDown("Fire"+ playerNumber))
			{
				fire();
				CDtime = 0;
			}
		}
		if(CDtime >0.6f&&ShellValue == 2)
		{
			RedFire();
			CDtime = 0;
		}
	}
	private void RedFire()
	{	
		if (Input.GetButtonDown("Fire"+ playerNumber)) {
	       //fire();
		   fireForce = minForce;
	    }
		else if(Input.GetButton("Fire"+ playerNumber)) {
			fireForce += Time.deltaTime * (maxForce - minForce)/forceLoadingTime;
		}
		else if(Input.GetButtonUp("Fire"+playerNumber)) {
				if(fireForce > maxForce) fireForce = maxForce;
				GameObject redshell = Instantiate(RedShellPrefab,firePoint.position,firePoint.rotation);
				Rigidbody rb = redshell.GetComponent<Rigidbody>();
				rb.velocity = firePoint.forward * fireForce;
			}
		fireForce = minForce;
		SetAimSlider();
	}
	private void fire()
	{
		if (Input.GetButtonDown("Fire"+ playerNumber)) {
	       //fire();
		   fireForce = minForce;
	    }
		else if(Input.GetButton("Fire"+ playerNumber)) {
			fireForce += Time.deltaTime * (maxForce - minForce)/forceLoadingTime;
		}
		else if(Input.GetButtonUp("Fire"+playerNumber)) {
			if(fireForce > maxForce/2) fireForce = maxForce/2;
			GameObject shell = Instantiate(shellPrefab,firePoint.position,firePoint.rotation);
			Rigidbody rb = shell.GetComponent<Rigidbody>();
			rb.velocity = firePoint.forward * fireForce;
			}
		fireForce = minForce;
		
		SetAimSlider();
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
