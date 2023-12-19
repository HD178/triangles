import java.util.Scanner;
import java.util.InputMismatchException;

public class NForce {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		//height input
		System.out.print("Enter height: ");
		String heightStr = scanner.nextLine();
		if (Input(heightStr) == -1) {
			System.out.println();
			System.out.println("Invalid height.");
			return;
		}
		int height = Input(heightStr);

		//row input
		System.out.print("Enter number of rows: ");
		String rowsStr = scanner.nextLine();
		if (Input(rowsStr) == -1) {
			System.out.println();
			System.out.println("Invalid number of rows.");
			return;
		}
		int rows = Input(rowsStr);

		//actual print
		System.out.println();
		print(height, rows);
	}

	public static void print(int height, int rows) {

		for (int a = 0; a < (height*rows); a++) {
		for (int b = 1; b < height*rows - a; b++) { //left side spaces
			System.out.print(" ");
		}

		System.out.print("/");

		for (int c = 0; c < (a*2); c++) { //triangle guts
			//if negative slope
			if (c%(height*2) == (2*(height) - (2 * (height-(a) % height) ))%(height*2) && a/height != 0) {
			System.out.print("\\");
			}
			//else if positive slope
			else if (c%(height*2) == ((a*2-1) - (2*(height) - (2 * (height-(a) % height) )))%(height*2) && a/height != 0) {
			System.out.print("/");
			}


			else if (( (a%height) == (height-1) ) && height!=1) {
			System.out.print("_");
			}

			else {
			System.out.print(" ");
			}
		}

		System.out.print("\\");

		System.out.println();
		}
	}


  public static int Input(String input) {
    try {
      if (input.isEmpty()) {
        return -1;
      }

      int result = Integer.parseInt(input);

      if (result <= 0 || result > 20) {
        return -1;
      }
      return result;
    }
    catch (InputMismatchException e) {
      return -1;
    }
    catch (NumberFormatException e) {
      return -1;
    }
  }

}
