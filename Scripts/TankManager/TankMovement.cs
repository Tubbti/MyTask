using UnityEngine;
using System.Collections;
using UnityEditor;

public class TankMovement : MonoBehaviour {

    public float moveSpeed = 5;
    public float turnSpeed = 50;
    [SerializeField]
    private int playerNumber = 1;
    private float turnValue;
    private float moveValue;
    public AudioClip idleAudio;
    public AudioClip drivingAudio;

    private AudioSource Moveaudio;
    private Rigidbody rb;

	// Use this for initialization
	void Start () {
	    rb = this.GetComponent<Rigidbody>();
	    Moveaudio = this.GetComponent<AudioSource>();
	}
    void Update() {
        moveValue = Input.GetAxis("VerticalPlayer"+playerNumber);
        turnValue = Input.GetAxis("HorizontalPlayer"+playerNumber);
    }
    void FixedUpdate()
    {
        move();
        turn();
    }
    private void move()
    {
        Vector3 position = transform.forward * moveValue * Time.deltaTime * moveSpeed;
        rb.MovePosition(rb.position + position);
    }
    private void turn()
    {
        float turn = turnValue * Time.deltaTime * turnSpeed;
        Quaternion rotation = Quaternion.Euler(0,turn,0);
        rb.MoveRotation(rb.rotation * rotation);
    }
    public void SetPlayerNumber(int playerNumber)
    {
        this.playerNumber = playerNumber;
    }
}
