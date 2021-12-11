using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
public class Tank : MonoBehaviour
{
    public Color skinColor;
    public Transform spawnPoint;
    public GameObject tankGameObject;
    public int playerNumber;
    public int ShellValue = 1;
    public int counts = 2;
    public void SetTankColor(Color color)
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
        this.ShellValue = 1;
        SetTankColor(this.skinColor);
        SetTankPlayerNumber(this.playerNumber);
    }
    public GameObject GetTankGameObject()
    {
        return tankGameObject;
    }
}
