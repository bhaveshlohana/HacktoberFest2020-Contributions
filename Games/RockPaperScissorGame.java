import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.control.Label;
import java.util.Random;

public class RockPaperScissorGame extends Application
{
   // Initialize variables
   String compPick;
   int userSelection;
   int firstRand;
   // Game Labels
   Label gameResults = new Label("Results: ");
   Label compChoiceLabel = new Label("Computer chose: ");
 
   public static void main(String[] args)
   {
      // Launch the application.
       launch(args);
   }
  
   @Override
   public void start(Stage primaryStage)
   {  
      // Images and ImageViews for Rock, Paper and Scissors      
      Image rockImg = new Image("file:gameImg1.png");
      ImageView rockView = new ImageView(rockImg);
      
      Image scissorImg = new Image("file:gameImg2.png");
      ImageView scissorView = new ImageView(scissorImg);
      
      Image paperImg = new Image("file:gameImg3.png");
      ImageView paperView = new ImageView(paperImg);
      
      // Placeholder image to get started for computer choice
      Image placeHolder = new Image("file:gameImg1.png");
      ImageView computerChoiceView = new ImageView(placeHolder);
      
      // Label to display rules and player choice
      Label gameRules = new Label("Click one of three images on top section to make your choice. \nImage on the bottom will display computers choice. Game results will show who wins.");
      Label playerChoiceLabel = new Label("You chose: ");
     
      // Mouse pressed event for when rock is chosen by player 
      rockView.setOnMousePressed(event -> 
      {
         userSelection = 1;
         firstRand = randComp();
         computerChoiceView.setImage(new Image("file:gameImg"+firstRand+".png"));
         compChoice(firstRand);
         playerChoiceLabel.setText("You chose: Rock");
      });
      
      // Mouse pressed event for when scissors is chosen by player
      scissorView.setOnMousePressed(event ->
      {
         userSelection = 2;
         firstRand = randComp();
         computerChoiceView.setImage(new Image("file:gameImg"+firstRand+".png"));
         compChoice(firstRand);
         playerChoiceLabel.setText("You chose: Scissors");
      });
      
      // Mouse pressed event for when paper is chosen by player
      paperView.setOnMousePressed(event ->
      {
         userSelection = 3;
         firstRand = randComp();
         computerChoiceView.setImage(new Image("file:gameImg"+firstRand+".png"));
         compChoice(firstRand);
         playerChoiceLabel.setText("You chose: Paper");
      });
      
      // Side by side view for rock, paper, scissors     
      HBox hbox = new HBox(rockView, scissorView, paperView);
      // Verticle view for remaining game elements
      VBox vbox = new VBox(20, gameRules, compChoiceLabel, playerChoiceLabel, hbox,  computerChoiceView, gameResults);
      
      Scene scene = new Scene(vbox);
      primaryStage.setScene(scene);
      primaryStage.setTitle("Rock, Paper, Scissors");
      primaryStage.show();
   }
   
   // determines win results based on user selection and computer choice
   private void userChoice() {
      if(userSelection == 1 && compPick.equals("rock") || userSelection == 2 && compPick.equals("scissors") || userSelection == 3 && compPick.equals("paper")) {
         gameResults.setText("Results: It is a tie.");
      } else if(userSelection == 1 && compPick.equals("paper") || userSelection == 2 && compPick.equals("rock") || userSelection == 3 && compPick.equals("scissors")){
         gameResults.setText("Results: you lose.");
      } else if(userSelection == 1 && compPick.equals("scissors") || userSelection == 2 && compPick.equals("paper") || userSelection == 3 && compPick.equals("rock")) {
         gameResults.setText("Results: you win");
      }
   }
   
   // determines which selection (rock, paper, scissors) computer chose
   private void compChoice(int num) {
      num = firstRand;
      if(num == 1) {
         compPick = "rock";
      } else if (num == 2) {
         compPick = "scissors";
      } else if (num == 3) {
         compPick = "paper";         
      }
      switch(compPick) {
         case "rock":
            compChoiceLabel.setText("Computer chose: Rock");
            userChoice();
            break;
         case "scissors":
            compChoiceLabel.setText("Computer chose: Scissors");
            userChoice();
            break;
         case "paper": 
            compChoiceLabel.setText("Computer chose: Paper");
            userChoice();
            break;
         default:
            System.out.println("Incorrect value.");
            break;
      }
   }
   
   // Randomizes computers choice
   private int randComp() {
       Random rand = new Random();
       firstRand = rand.nextInt(3) + 1;
       return firstRand;
   }
 
}
