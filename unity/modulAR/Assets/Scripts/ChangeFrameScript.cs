using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeFrameScript : MonoBehaviour
{
    public GameObject currentFrame;
    public GameObject nextFrame;


    public void whenButtonClicked ()
    {
        nextFrame.SetActive(true);
        currentFrame.SetActive(false);
    }
}
