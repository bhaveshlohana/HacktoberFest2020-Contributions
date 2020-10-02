using UnityEngine;
using System.Collections;
using UnityEngine.UI;
public class GridSpace : MonoBehaviour {
	public Button button;
	private Gamecontroller gameController;
	public Text buttonText;
	public void SetSpace ()
	{
		buttonText.text = gameController.getplayerside();
		button.interactable = false;
		gameController.asign(button);
	}
		
	public void SetGameControllerReference (Gamecontroller controller)
	{
		gameController = controller;
	}
}