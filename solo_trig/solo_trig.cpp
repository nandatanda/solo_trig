#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

int main()
{
	int menu_selection = 0;
	int side_count = 0;
	int solve_for = 0;
	double side_opp = 0;
	double side_adj = 0;
	double side_hyp = 0;
	double angle_a = 0;

	std::cout << "TRIG: THE SEQUEL\n\n\nSolve:\n\n[1] Side\n\n[2] Angle\n\n>"; // MAIN MENU
	std::cin >> menu_selection;

	if (menu_selection == 1) // MAIN MENU > SIDE
	{
		std::cout << "\n\nSolve Using:\n\n[1] Pythagoras' Theorem\t\t(we know the other two sides)\n\n[2] Trig Ratio\t\t\t(we know an angle and a side)\n\n>";
		std::cin >> menu_selection;

		if (menu_selection == 1) // MAIN MENU > SIDE > PYTHAGORAS' THEOREM
		{
			std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nLeg 'a'\t\t>";
			std::cin >> side_opp;
			std::cout << "\nLeg 'b'\t\t>";
			std::cin >> side_adj;
			std::cout << "\nHypnotenuse\t>";
			std::cin >> side_hyp;

			((side_opp == 0) ? solve_for = 1 : side_count++);
			((side_adj == 0) ? solve_for = 2 : side_count++);
			((side_hyp == 0) ? solve_for = 3 : side_count++);

			if (side_count == 3) // Too much information.
			{
				std::cout << "\nThere are no unknown sides. Try again.\n\n";
			}
			else if (side_count <= 1) // Not enough information
			{
				std::cout << "\nThere are too many unknown sides. Try a different solving method.\n\n";
			}
			else // Doing math.
			{
				if (solve_for == 1)
				{
					side_opp = sqrt((side_hyp * side_hyp) - (side_adj * side_adj));
					std::cout << "\n\nThe length of leg 'a' is " << side_opp << ".\n\n";
				}
				else if (solve_for == 2)
				{
					side_adj = sqrt((side_hyp * side_hyp) - (side_opp * side_opp));
					std::cout << "\n\nThe length of leg 'b' is " << side_adj << ".\n\n";
				}
				else if (solve_for == 3)
				{
					side_hyp = sqrt((side_opp * side_opp) + (side_adj * side_adj));
					std::cout << "\n\nThe length of the hypotenuse is " << side_hyp << ".\n\n";
				}
			}	
		}	
		else if (menu_selection == 2) // MAIN MENU > SIDE > TRIG RATIO
		{
			std::cout << "\n\nRatio:\n\n[1] Sine Ratio\t\t\t(sin(?) = opposite / hypotenuse)\n\n[2] Cosine Ratio\t\t(cos(?) = adjacent / hypotenuse)\n\n[3] Tangent Ratio\t\t(tan(?) = opposite / adjacent)\n\n>";
			std::cin >> menu_selection; // Selecting trigonometric ratio.

			if (menu_selection == 1) // Solving with sine.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >>angle_a;
				std::cout << "\nOpposite\t>";
				std::cin >> side_adj;
				std::cout << "\nHypnotenuse\t>";
				std::cin >> side_hyp;
				
				if (side_adj == 0 && side_hyp == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (side_adj == 0) // Solving for the opposite.
				{
					side_adj = side_hyp * (sin(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the opposite side is " << side_adj << ".\n\n";
				}
				else if (side_hyp == 0) // Solving for the hypotenuse.
				{
					side_hyp = side_adj / (sin(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the hypotenuse is " << side_hyp << ".\n\n";
				}
			}
			else if (menu_selection == 2) // Solving with cosine.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >> angle_a;
				std::cout << "\nAdjacent\t>";
				std::cin >> side_adj;
				std::cout << "\nHypnotenuse\t>";
				std::cin >> side_hyp;
			
				if (side_adj == 0 && side_hyp == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (side_adj == 0) // Solving for the adjacent.
				{
					side_adj = side_hyp * (cos(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the adjacent side is " << side_adj << ".\n\n";
				}
				else if (side_hyp == 0) // Solving for the hypotenuse.
				{
					side_hyp = side_adj / (cos(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the hypotenuse is " << side_hyp << ".\n\n";
				}
			}
			else if (menu_selection == 3) // Solving with tangent.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >> angle_a;
				std::cout << "\nOpposite\t>";
				std::cin >> side_opp;
				std::cout << "\nAdjacent\t>";
				std::cin >> side_adj;

				if (side_opp == 0 && side_adj == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (side_opp == 0) // Solving for the opposite.
				{
					side_opp = side_adj * (tan(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the opposite side is " << side_opp << ".\n\n";
				}
				else if (side_hyp == 0) // Solving for the adjacent.
				{
					side_adj = side_opp / (tan(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the adjacent side is " << side_adj << ".\n\n";
				}
			}
		}
		
		menu_selection = 1;
	}
	if (menu_selection == 2) // MAIN MENU -> ANGLE
	{
		std::cout << "\n\nSolve Using:\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nOpposite\t>";
		std::cin >> side_opp;
		std::cout << "\nAdjacent\t>";
		std::cin >> side_adj;
		std::cout << "\nHypnotenuse\t>";
		std::cin >> side_hyp;
		
		((side_opp == 0) ? solve_for = 1 : side_count++);
		((side_adj == 0) ? solve_for = 2 : side_count++);
		((side_hyp == 0) ? solve_for = 3 : side_count++);

		if (side_count <= 1) // Cannot solve.
		{
			std::cout << "\nThere are too many unknown sides. Try a different solving method.\n\n.";
		}
		else
		{
			if (side_adj == 0 || solve_for == 0) // Solving with sine.
			{
			angle_a = asin(side_opp / side_hyp) * (180 / M_PI);
			std::cout << "\nThe sine ratio is " << side_opp << " over " << side_hyp <<  ". The degree value of the angle is " << angle_a << ".\n\n";
			}
			else if (side_opp == 0) // Solving with cosine.
			{
				angle_a = acos(side_adj / side_hyp) * (180 / M_PI);
				std::cout << "\nThe cosine ratio is " << side_adj << " over " << side_hyp << ". The degree value of the angle is " << angle_a << ".\n\n";
			}
			else if (side_hyp == 0) // Solving with tangent.
			{
				angle_a = atan(side_opp / side_adj) * (180 / M_PI);
				std::cout << "\nThe sine ratio is " << side_opp << " over " << side_adj << ". The degree value of the angle is " << angle_a << ".\n\n";
			}
		}
	}

	return 0;
}