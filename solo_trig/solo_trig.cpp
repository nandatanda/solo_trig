#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

int main()
{
	int menu_selection = 0;
	int side_count = 0;
	int solve_for = 0;
	double leg_a = 0;
	double leg_b = 0;
	double hyp_c = 0;
	double angle_a = 0;
	double angle_b = 0;
	double angle_c = 0;
	double calc_total = 0;
	double calc_sin = 0;
	bool check_triangle1 = true;
	bool check_triangle2 = true;

	std::cout << "TRIG: THE SEQUEL\n\n\nSolve:\n\n[1] Side\n\n[2] Angle\n\n>"; // Main Menu.
	std::cin >> menu_selection;

	if (menu_selection == 1) // Main Menu -> Side Solver
	{
		std::cout << "\n\nSolve Using:\n\n[1] Pythagoras' Theorem\t\t(we know the other two sides)\n\n[2] Trig Ratios\t\t\t(we know an angle and a side)\n\n>";
		std::cin >> menu_selection;

		if (menu_selection == 1) // Solving a side using two other sides (Pythagoras' Theorem).
		{
			std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nLeg 'a'\t\t>";
			std::cin >> leg_a;
			std::cout << "\nLeg 'b'\t\t>";
			std::cin >> leg_b;
			std::cout << "\nHypnotenuse\t>";
			std::cin >> hyp_c;

			((leg_a == 0) ? solve_for = 1 : side_count++);
			((leg_b == 0) ? solve_for = 2 : side_count++);
			((hyp_c == 0) ? solve_for = 3 : side_count++);

			if (side_count == 3) // Too much or not enough information.
			{
				std::cout << "\nThere are no unknown sides. Try again.\n\n";
			}
			else if (side_count == 1)
			{
				std::cout << "\nThere are too many unknown sides. Try a different solving method.\n\n.";
			}
			else // Doing math.
			{
				if (solve_for == 1)
				{
					leg_a = sqrt((hyp_c * hyp_c) - (leg_b * leg_b));
					std::cout << "\n\nThe length of leg 'a' is " << leg_a << ".\n\n";
				}
				else if (solve_for == 2)
				{
					leg_b = sqrt((hyp_c * hyp_c) - (leg_a * leg_a));
					std::cout << "\n\nThe length of leg 'b' is " << leg_b << ".\n\n";
				}
				else if (solve_for == 3)
				{
					hyp_c = sqrt((leg_a * leg_a) + (leg_b * leg_b));
					std::cout << "\n\nThe length of the hypotenuse is " << hyp_c << ".\n\n";
				}
			}	
		}	
		else if (menu_selection == 2) // Solving a side using an angle and a another side. (trig ratios)
		{
			std::cout << "\n\nRatio:\n\n[1] Sine Ratio\t\t\t(sin(?) = opposite / hypotenuse)\n\n[2] Cosine Ratio\t\t(cos(?) = adjacent / hypotenuse)\n\n[3] Tangent Ratio\t\t(tan(?) = opposite / adjacent)\n\n>";
			std::cin >> menu_selection; // Selecting trigonometric ratio.

			if (menu_selection == 1) // Solving with sine.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >>angle_a;
				std::cout << "\nOpposite\t>";
				std::cin >> leg_b;
				std::cout << "\nHypnotenuse\t>";
				std::cin >> hyp_c;
				
				if (leg_b == 0 && hyp_c == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (leg_b == 0) // Solving for the opposite.
				{
					leg_b = hyp_c * (sin(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the opposite side is " << leg_b << ".\n\n";
				}
				else if (hyp_c == 0) // Solving for the hypotenuse.
				{
					hyp_c = leg_b / (sin(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the hypotenuse is " << hyp_c << ".\n\n";
				}
			}
			else if (menu_selection == 2) // Solving with cosine.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >> angle_a;
				std::cout << "\nAdjacent\t>";
				std::cin >> leg_b;
				std::cout << "\nHypnotenuse\t>";
				std::cin >> hyp_c;
			
				if (leg_b == 0 && hyp_c == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (leg_b == 0) // Solving for the adjacent.
				{
					leg_b = hyp_c * (cos(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the adjacent side is " << leg_b << ".\n\n";
				}
				else if (hyp_c == 0) // Solving for the hypotenuse.
				{
					hyp_c = leg_b / (cos(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the hypotenuse is " << hyp_c << ".\n\n";
				}
			}
			else if (menu_selection == 3) // Solving with tangent.
			{
				std::cout << "\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nAngle\t\t>";
				std::cin >> angle_a;
				std::cout << "\nOpposite\t>";
				std::cin >> leg_a;
				std::cout << "\nAdjacent\t>";
				std::cin >> leg_b;

				if (leg_a == 0 && leg_b == 0 || angle_a == 0) // Not enough information.
				{
					std::cout << "\n\nThere is not enough information to solve.\n\n";
				}
				else if (leg_a == 0) // Solving for the opposite.
				{
					leg_a = leg_b * (tan(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the opposite side is " << leg_a << ".\n\n";
				}
				else if (hyp_c == 0) // Solving for the adjacent.
				{
					leg_b = leg_a / (tan(angle_a * (M_PI / 180)));
					std::cout << "\n\nThe length of the adjacent side is " << leg_b << ".\n\n";
				}
			}
		}
	}
	if (menu_selection == 2) // Main Menu -> Angle Solver
	{
			std::cout << "\n\nSolve Using:\n\nName\t\tValue\t\t(enter '0' if unknown)\n\nOpposite\t>";
			std::cin >> leg_a;
			std::cout << "\nAdjacent\t>";
			std::cin >> leg_b;
			std::cout << "\nHypnotenuse\t>";
			std::cin >> hyp_c;
		
			((leg_a == 0) ? solve_for = 1 : side_count++);
			((leg_b == 0) ? solve_for = 2 : side_count++);
			((hyp_c == 0) ? solve_for = 3 : side_count++);

			if (side_count == 0 || side_count == 1) // Cannot solve.
			{
				std::cout << "\nThere are too many unknown sides. Try a different solving method.\n\n.";
			}
			else
			{
				if (leg_b == 0 || solve_for == 0) // Solving with sine.
				{
					angle_a = asin(leg_a / hyp_c) * (180 / M_PI);
					std::cout << "\nThe sine ratio is " << leg_a << " over " << hyp_c <<  ". The degree value of the angle is " << angle_a << ".\n\n";
				}
				else if (leg_a == 0) // Solving with cosine.
				{
					angle_a = acos(leg_b / hyp_c) * (180 / M_PI);
					std::cout << "\nThe cosine ratio is " << leg_b << " over " << hyp_c << ". The degree value of the angle is " << angle_a << ".\n\n";
				}
				else if (hyp_c == 0) // Solving with tangent.
				{
					angle_a = atan(leg_a / leg_b) * (180 / M_PI);
					std::cout << "\nThe sine ratio is " << leg_a << " over " << leg_b << ". The degree value of the angle is " << angle_a << ".\n\n";
				}
			}
	}
	
	return 0;
}