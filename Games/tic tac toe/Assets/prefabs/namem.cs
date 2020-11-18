using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class namem : MonoBehaviour {
	public InputField p1,p2;
	private string p1n,p2n;
	public void setname()
	{   
		p1n = p1.text;
		p2n = p2.text;
		data.p1 = p1n;
		data.p2 = p2n;
		SceneManager.LoadScene ("main", LoadSceneMode.Single);
	}
}
