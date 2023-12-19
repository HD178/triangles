import java.util.Scanner;

public class Triforce {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(System.in);
			System.out.print("Enter height: ");
			String input = scanner.nextLine();
			int height = Integer.parseInt(input);

			if (height < 2 || height > 20) {
				System.out.println();
				System.out.println("Invalid height.");
				return;
			}

			System.out.println();

			//top triangle
			for (int a = 0; a < height - 1; a++) {
				for (int b = 1; b < height*2 - a; b++) { //left side spaces
					//System.out.print(" ");
					System.out.print(" ");
				}

				System.out.print("/");

				for (int c = 0; c < (a*2); c++) { //middle spaces
					System.out.print(" ");
				}

				System.out.print("\\");

				System.out.println();
			}

			//last line (----)
			for (int d = 0; d < height; d++) {
				//System.out.print(" ");
				System.out.print(" ");
			}

			System.out.print("/");

			for (int e = 0; e < (2*(height-1)); e++) {
				System.out.print("_");
			}

			System.out.print("\\");

			System.out.println();


			//bottom triangle
			for (int f = 0; f < height - 1; f++) {
				for (int g = 1; g < height - f; g++) { //left spaces
					System.out.print(" ");
				}

				System.out.print("/");

				for (int h = 0; h < f*2; h++) { //left triangle spaces
					System.out.print(" ");
				}

				System.out.print("\\");

				for (int i = (height*2)-(f*2) - 2; i > 0; i--) { //mid triangle spaces
					System.out.print(" ");
				}

				System.out.print("/");


				for (int j = 0; j < f*2; j++) { //right triangle spaces
					System.out.print(" ");
				}

				System.out.print("\\");

				System.out.println();
			}

			//bottom triangle lines (-----)
			System.out.print("/");
			for (int k = 0; k < (2*(height-1)); k++) {
				System.out.print("_");
			}

			System.out.print("\\/");

			for (int l = 0; l < (2*(height-1)); l++) {
				System.out.print("_");
			}

			System.out.println("\\");

		}
		catch (NumberFormatException e) {
			System.out.println();
			System.out.println("Invalid height.");
		}


	}
}
