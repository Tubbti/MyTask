using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TankManager : MonoBehaviour
{
    private ArrayList tanks = new ArrayList();
    public void AddTank(Tank tank)
    {
        tanks.Add(tank);
    }
    public Transform[] GetTanksTransforms()
    {
        Transform[] targets = new Transform[tanks.Count];
       for(int i=0;i<tanks.Count;i++)
       {
           Tank tank = (Tank)tanks[i];
           targets[i] = tank.GetTankGameObject().transform;
       }
       return targets;
    }
}
