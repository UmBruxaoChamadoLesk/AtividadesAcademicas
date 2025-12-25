package Pacote;

import java.util.Scanner;

public class TrianguloApp 
{

	public static void main(String []args)
	{
		
		Scanner Roberto = new Scanner(System.in);
		
		Triangulo T1,T2;
		T1 = new Triangulo();
		T2 = new Triangulo();
		
			System.out.println("declare as 3 areas do triangulo T1");
			
			T1.a = Roberto.nextDouble();
			T1.b = Roberto.nextDouble();
			T1.c = Roberto.nextDouble();
			
		
			System.out.println("declare as 3 areas do triangulo T2");
			
			T2.a = Roberto.nextDouble();
			T2.b = Roberto.nextDouble();
			T2.c = Roberto.nextDouble();
			
		
		
		System.out.format("\nAs areas de cada respectivo triangulo em sequência são:\nT1:%.10f\nT2:%.10f\n",T1.area(),T2.area());


		if(T1.area() > T2.area())
		{
			System.out.println("Maior area:T1");
		
		}
		else
		{
			System.out.println("Maior area:T2");

		}
	
		
		Roberto.close();		
	}
	
}
