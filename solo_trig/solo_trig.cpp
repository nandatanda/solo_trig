#include <iostream>
#include <cmath>

int main()
{
	int menu_selection = 0;
	int side_count = 0;
	int solve_for = 0;
	double side_lega = 0;
	double side_legb = 0;
	double side_hypo = 0;
	double calc_angle1 = 0;
	double calc_angle2 = 0;
	double calc_angle3 = 0;
	double calc_total = 0;
	double calc_sin = 0;
	bool check_triangle1 = true;
	bool check_triangle2 = true;

	std::cout << "TRIG: THE SEQUEL\n\n\nSolve:\n\n[1] Side\n\n[2] Angle\n\n>";
	std::cin >> menu_selection;

	if (menu_selection == 1)
	{
		std::cout << "\n\n\t          /|\n\t         / |\n\t        /  |\n\t       /   |\n\t      /    |\n\t    (c)    |\n\t    /     (a)\n\t   /       |\n\t  /        |\n\t /         |\n\t/___(b)____|";
		
		std::cout << "\n\nInput Sides:\t(Set unknown information to zero)\n\nLeg 'a':\n>";
		std::cin >> side_lega;
		std::cout << "\nLeg 'b':\n>";
		std::cin >> side_legb;
		std::cout << "\nHypotnuse:\n>";
		std::cin >> side_hypo;
		
		((side_lega == 0) ? solve_for = 1 : side_count++);
		((side_legb == 0) ? solve_for = 2 : side_count++);
		((side_hypo == 0) ? solve_for = 3 : side_count++);

		if (side_count == 3)
		{
			std::cout << "\nThis triangle is already solved.\n";
		}
		else
		{
			std::cout << "\n" << side_count;
		}
	
	
	
	}

	else if (menu_selection == 2)
	{

	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	//take the known dimensions of the triangle
	
	std::cout << "INPUTS\n\nSide 1:\n>";
	std::cin >> calc_side1;
	std::cout << "\nSide 2:\n>";
	std::cin >> calc_side2;
	std::cout << "\nSide 3:\n>";
	std::cin >> calc_side3;
	std::cout << "\nAngle 1:\n>";
	std::cin >> calc_angle1;
	std::cout << "\nAngle 2:\n>";
	std::cin >> calc_angle2;
	std::cout << "\nAngle 3:\n>";
	std::cin >> calc_angle3;
	std::cout << "\n" << calc_side1 << "\n" << calc_side2 << "\n" << calc_side3 << "\n" << calc_angle1 << "\n" << calc_angle2 << "\n" << calc_angle3;
	
	//check if this triangle exists
	
	if (calc_side1 != 0 && calc_side2 != 0 && calc_side3 != 0)
	{
		if ((calc_side1 + calc_side2 <= calc_side3) && (calc_side2 + calc_side3 <= calc_side1) && (calc_side3 + calc_side1 <= calc_side2))
		{
			check_triangle1 = false;
		}
	}
	else if (calc_angle1 != 0 && calc_angle2 != 0 && calc_angle3 != 0)
	{
		calc_total = (calc_angle1 + calc_angle2 + calc_angle3);
		if (calc_total != 180)
		{
			std::cout << "\nNo such triangle exists.";
		}
	}

	return 0;
}
*/
