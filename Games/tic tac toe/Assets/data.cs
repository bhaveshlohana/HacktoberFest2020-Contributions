using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class data
{
	private static string p1name,p2name;
	private static int dif;
	public static string p1
	{
		get{return p1name;}
		set{p1name = value;}
	}
	public static string p2
	{
		get{return p2name;}
		set{p2name = value;}
	}
	public static int diff
	{
		get{return dif;}
		set{dif=value;}
	}
}
