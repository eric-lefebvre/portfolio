import java.io.IOException;

public class MainFormation {
  
  public static void main(String[] args) {
    // TODO Auto-generated method stub
    System.out.println("\nAppuyez sur Entree pour terminer le programme ...");
    try {
      System.in.read();
    } catch (IOException e) {
      System.err.println("Vous avez reussi a casser le clavier : " + e);
    }
  }
}

