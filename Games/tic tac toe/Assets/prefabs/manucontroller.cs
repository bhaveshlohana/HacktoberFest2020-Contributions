using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class manucontroller : MonoBehaviour {
	enum dif
	{
		none,easy,medium,hard
	}
	public GameObject mcanvas, dcanvas,ccredits;
	void Awake()
	{
		dcanvas.SetActive (false);
		ccredits.SetActive (false);
	}
	public void sp ()
	{
		mcanvas.SetActive (false);
		dcanvas.SetActive (true);
		ccredits.SetActive (false);
	}
	public void ex()
	{
		Application.Quit ();
	}
	public void back()
	{
		mcanvas.SetActive (true);
		dcanvas.SetActive (false);
		ccredits.SetActive (false);
	}
	public void about()
	{
		mcanvas.SetActive (false);
		dcanvas.SetActive (false);
		ccredits.SetActive (true);
	}
	public void easy ()
	{
		data.diff = (int)dif.easy;
		SceneManager.LoadScene ("main", LoadSceneMode.Single);
	}
	public void medium ()
	{
		data.diff = (int)dif.medium;
		SceneManager.LoadScene ("main", LoadSceneMode.Single);
	}
	public void veteran ()
	{
		data.diff = (int)dif.hard;
		SceneManager.LoadScene ("main", LoadSceneMode.Single);
	}
	public void twop()
	{
		data.diff = (int)dif.none;
		SceneManager.LoadScene ("namemenu", LoadSceneMode.Single);
	}
}
