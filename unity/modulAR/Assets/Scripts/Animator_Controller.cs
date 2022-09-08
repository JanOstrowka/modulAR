using UnityEngine;
using System.Collections;

public class Animator_Controller : MonoBehaviour
{

    Animator animator;


    void Start()
    {
        animator = GetComponent<Animator>();
    }


    void OnMouseDown()
    {
               animator.SetTrigger("click");
    }
    }