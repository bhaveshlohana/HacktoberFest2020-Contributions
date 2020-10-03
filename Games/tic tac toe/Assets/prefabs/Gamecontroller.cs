using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System;
using UnityEngine.SceneManagement;
using System.Collections.Generic;

public class Gamecontroller : MonoBehaviour {
	public GameObject gameoverpanel,endpanel;
	public Text gameovertext;
	public Text[] buttonList;
	private int[] buttlist=new int[9];
	public Button endb;
	int origdepth;
	int[] postions=new int[9],win=new int[9];
	int[] board = new int[9];
	//Dtionary<int,string> map=new Dictionary<int,string>();
	Dictionary<int,int> sample=new Dictionary<int,int>();
	readonly int[] magicsq = { 2, 7, 6, 9, 5, 1, 4, 3, 8 };
	private string playerSide;
	private string compside,pside;
	int turns=0;
	System.Random rnd=new System.Random();
	private string name1,name2;
	public delegate void playai();
	public playai playmove;
	void setai(int lev)
	{
		if(lev==1)
			playmove=beginner;
		else if(lev==2)
			playmove=inter;
		else if(lev==3)
			playmove=advn;
		else
			playmove=none;
	}
	ArrayList filterboard(int [] tboard)
	{
		ArrayList emptyboard = new ArrayList ();
		emptyboard.Clear ();
		for(int i=0;i<9;i++) 
		{
			if (tboard [i] == 0)
				emptyboard.Add (i);
		}
		return (shuffle(emptyboard));
	}
	ArrayList shuffle(ArrayList b)
	{ 
		ArrayList sort = new ArrayList();
		System.Random gen = new System.Random();
		while (b.Count > 0)
		{
			int pos = gen.Next(b.Count);
			sort.Add(b[pos]);
			b.RemoveAt(pos);
		}
		return sort;
	}
	public void beginner()
	{	ArrayList emptyboard = filterboard (board);
		int move=rnd.Next(emptyboard.Count);
		int pos = (int)emptyboard [move];
		compmove (pos);
	}
	public void inter()
	{	
		int i = checkturn (board,"X"); 
		int j = checkturn (board,"O");
		ArrayList emptyboard = filterboard (board);
		if (i!=-20)
		{
			compmove (i);
			return;
		} else if (j!=-20)
		{
			compmove (j);
			return;
		}
		else 
		{
			int move=rnd.Next(emptyboard.Count);
			int pos = (int)emptyboard [move];
			compmove (pos);
		}
	}
	public void advn()
	{
		System.Random rn = new System.Random ();
		ArrayList fm = filterboard (board);
		int p;
		if (fm.Count == 9) {
			p = rn.Next (9);
			compmove (p);
		} else {
			p = min_max(board,compside);
			compmove (p);
		}
	}
	public int min_max(int[] tboard, string symbol)
	{
		int bestval = -1000;
		int bestmove = -1;
		ArrayList eboard = new ArrayList();
		eboard = filterboard(tboard);
		int nsymbol = (symbol == "X" ? 1 : 2);
		for (int i = 0; i < eboard.Count; i++)
		{
			board[(int)eboard[i]] = nsymbol;
			int moveval = mini_max(board, changeside(symbol));
			if (moveval > bestval)
			{
				bestmove = (int)eboard[i];
				bestval = moveval;
			}
			board[(int)eboard[i]] = 0;
		}
		return bestmove;
	}
	public int mini_max(int[] tboard, string symbol)
	{
		int nsymbol = (symbol == "X" ? 1 : 2);
		int score = checkwin(tboard);
		if (score != -1)
		{
			if (compside == "X")
			{
				if (score == 1)
					return 10;
				else if (score == 2)
					return -10;
				else
					return 0;
			}
			else
			{
				if (score == 2)
					return 10;
				else if (score == 1)
					return -10;
				else
					return 0;
			}
		}
		ArrayList eboard = new ArrayList();
		eboard = filterboard(tboard);
		if (symbol==compside)
		{
			int best = -1000,tbest;
			for(int i =0;i<eboard.Count;i++)
			{
				board[(int)eboard[i]] = nsymbol;
				tbest = mini_max(tboard, changeside(symbol));
				if (tbest > best)
					best = tbest;
				board[(int)eboard[i]] = 0;
			}
			return best;
		}
		else
		{
			int best = 1000, tbest;
			for (int i = 0; i < eboard.Count; i++)
			{
				board[(int)eboard[i]] = nsymbol;
				tbest = mini_max(tboard, changeside(symbol));
				if (tbest < best)
					best = tbest;
				board[(int)eboard[i]] = 0;
			}
			return best;
		}
	}
	public void none()
	{
		//do nothing
	}
	void singp()
	{
		compside = "O";
		pside = "X";
		int fmove = rnd.Next (2);
		if (fmove == 1) 
		{
			data.p2 = "Congratulations! You";
			data.p1 = "THE CREATOR";
			compside = "X";
			pside = "O";
			playmove ();
		} 
		else 
		{
			data.p1= "Congratulations! You";
			data.p2 = "THE CREATOR";
		}
	}
	void compmove(int pos)
	{
		Button butt;
		buttonList [pos].text = compside;
		butt = buttonList [pos].GetComponentInParent<Button> ();
		butt.interactable = false;
		asign (butt);
	}
	void Start ()
	{
		setai (data.diff);
		for (int i = 0; i < 9; i++) 
		{
			sample.Add (magicsq [i], i);
			board [i] = 0;
		}
		endpanel.SetActive (false);
		gameoverpanel.SetActive (false);
		SetGameControllerReferenceOnButtons();
		playerSide = "X";
		if (!(data.diff == 0)) 
			singp();
	}
	void gameover (int win)
	{
		name1 = data.p1;
		name2 = data.p2;
		if (win==0) 
		{
			gameovertext.text = "GAME DRAWS!";
			gameoverpanel.SetActive (true);
		}
		else 
		{
			for (int i = 0; i < buttonList.Length; i++) {
				buttonList [i].GetComponentInParent<Button> ().interactable = false;
			}
			if (win==1) 
			{
				gameovertext.text = name1 + " WIN!";
				gameoverpanel.SetActive (true);
			} 
			else if (win==2)
			{
				gameovertext.text = name2 + " WIN!";
				gameoverpanel.SetActive (true);	
			}
		}
		endpanel.SetActive (true);
	}
	void SetGameControllerReferenceOnButtons ()
	{
		for (int i = 0; i < buttonList.Length; i++)
		{
			buttonList[i].GetComponentInParent<GridSpace>().SetGameControllerReference(this);
		}
	}
	void changeside()
	{
		playerSide=(playerSide=="X")?"O":"X";

	}
	string changeside(string symbol)
	{
		
		return (symbol=="X")?"O":"X";

	}
	public string getplayerside ()
	{
		return playerSide;
	}
	public void asign(Button butt)
	{   int j;
		int code = int.Parse (butt.tag);
		j = sample[code];
		if (playerSide == "X") 
			board [j] = 1;
		else
			board [j] = 2;
		endturn ();
	}
	int checkturn(int[] tboard,string symbol)
	{
		ArrayList emptyboard = filterboard (board);
		int j,i;
		int[] player = new int[5];
		for (i = 0; i < emptyboard.Count; i++) 
		{
			player = checkboard (tboard,symbol);
			for (j = 0; j < 5; j++)
				if (player [j] == 0)
					break;
			player [j] = magicsq [(int)emptyboard[i]];
			if (findtrip(player)) 
			{
				return (int)emptyboard [i];
			}
		}
		return -20;
	}
	public bool findtrip(int[] array)
	{
		Array.Sort (array);
		for(int i=0;i<3;i++)
		{
			if (array [i] == 0)
				continue;
			int l,r;
			l = i + 1;
			r = 4;
			while (l < r) 
			{  
				if (array [i] + array [l] + array [r] == 15) 
				{   
					if (!((array [i] == 0) || (array [l] == 0) || (array [r] == 0))) 
						return true;
				}
				else if (array [i] + array [l] + array [r] < 15)
					l++;
				else if (array [i] + array [l] + array [r] > 15)
					r--;				
			}
		}
		return false;
	}
	public int[] checkboard(int[] tboard,string symbol)
	{
		int j=0,nsymbol = (symbol == "X" ? 1 : 2);
		int[] player = new int[5];
		player.Initialize ();
		for (int i = 0; i < 9; i++) {
			if (tboard [i] == nsymbol)
				player [j++] = magicsq [i];
		}
		return player;
	}
	public int checkwin(int[] tboard)
	{
		ArrayList eboard = new ArrayList();
		eboard = filterboard(tboard);
		int[] player1 = new int[5];
		int[] player2 = new int[5];
		int winner = -1;
		player1 = checkboard(tboard, "X");
		player2 = checkboard(tboard, "O");
		if (findtrip(player1))
			winner = 1;
		else if (findtrip(player2))
			winner = 2;
		else if (eboard.Count == 0)
			winner = 0;
		return winner;
	}
	public void endturn ()
	{  
		int win;
		turns++;
		win = checkwin (board);
		if (!(win == -1))
			gameover (win);
		else 
		{
			changeside ();
			if (playerSide == compside)
				playmove ();
		}
	}
	public void endg()
	{
		SceneManager.LoadScene ("mainmenu", LoadSceneMode.Single);
	}
}

