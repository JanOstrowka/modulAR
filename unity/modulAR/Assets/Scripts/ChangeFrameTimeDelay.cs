using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeFrameTimeDelay : MonoBehaviour
{
    public GameObject currentFrame;
    public GameObject nextFrame;

    // Start is called before the first frame update
    void Start()
    {
        Invoke("ChangeFrame", 2);
    }

    public void ChangeFrame()
    {
        nextFrame.SetActive(true);
        currentFrame.SetActive(false);
    }
}
