using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
[Serializable]
public class Tank
{
    public Color skinColor;
    public Transform spawnPoint;
    [SerializeField]
    private GameObject tankGameObject;
    [SerializeField]
    private int playerNumber;
   // private int ShellValue = 1;
    private int roundWinnerCount = 0;
    private void SetTankColor(Color color)
    {
        MeshRenderer[] renderers = 
        tankGameObject.GetComponentsInChildren<MeshRenderer>();
        foreach(MeshRenderer renderer in renderers)
        {
            renderer.material.color = color;
        }
    }
    private void SetTankPlayerNumber(int playerNumber)
    {
        TankMovement tm = tankGameObject.GetComponent<TankMovement>();
        tm.SetPlayerNumber(playerNumber);
        TankAttack ts = tankGameObject.GetComponent<TankAttack>();
        ts.SetPlayerNumber(playerNumber);
    }
    public void Setup(GameObject tankGameObject,int number)
    {
        this.tankGameObject = tankGameObject;
        this.playerNumber = number;
       // this.ShellValue = 1;
        SetTankColor(this.skinColor);
        SetTankPlayerNumber(this.playerNumber);
    }
    public GameObject GetTankGameObject()
    {
        return tankGameObject;
    }
    public int GetRoundWinnerCount()
    {
        return roundWinnerCount;
    }
    public void IncreaseRoundWinnerCount()
    {
        roundWinnerCount++;
    } 
    public void Reset()
    {
        tankGameObject.SetActive(true);
        tankGameObject.transform.position = spawnPoint.position;
        tankGameObject.transform.rotation = spawnPoint.rotation;

        TankHealth th =this.tankGameObject.GetComponent<TankHealth>();
        th.ResetHealth();
    }
    public void Enable(bool enable)
    {
        TankAttack ts = this.tankGameObject.GetComponent<TankAttack>();
        ts.enabled = enable;
        TankMovement tm = this.tankGameObject.GetComponent<TankMovement>();
        tm.enabled = enable;
    }
}
