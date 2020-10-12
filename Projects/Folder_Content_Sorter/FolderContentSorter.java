/*
Folder Content Sorter moves contents of given directory to its respective categories depending on its match.
*/
import java.io.File;
import java.nio.file.Files;
import java.nio.file.*;
import java.util.Scanner; 
import java.io.IOException;
import java.util.regex.*;
public class ListOfFiles {
	/*
	Regex compiled patterns to match the file name and categorie it.
	*/
	private static Pattern image=Pattern.compile("([^\\s]+(\\.(?i)(jpe?g|png|gif|bmp|ico))$)");
	private static Pattern doc=Pattern.compile("([^\\s]+(\\.(?i)(txt|docx|pdf|doc|ppt|odt|xls|csv))$)");
	private static Pattern media=Pattern.compile("([^\\s]+(\\.(?i)(mp4|mp3|flv|avi))$)");
	private static Pattern code=Pattern.compile("([^\\s]+(\\.(?i)(py|pip|java|class|c|cpp|o|js|html|css))$)");
	//Utility function to move the file.
	private static void move(File from,String type) throws IOException{
		new File(from.getParent()+"/"+type).mkdir();
		Files.move(from.toPath(),Paths.get(from.getParent()+"/"+type+"/"+from.getName()));
		System.out.println("Successfully moved "+from.getName());
	}
	
	public static void main(String args[]) throws IOException {
		System.out.println("---------Folder Content Sorter------");
		System.out.println("Enter directory path:");
	    Scanner inputObject=new Scanner(System.in);
	    String path=inputObject.nextLine();
	    try{
		  	File directoryPath = new File(path);
		  	File filesList[] = directoryPath.listFiles();
		  	if(filesList==null)
		  	throw new NullPointerException();
		  	for(File file : filesList) {
		  		if(file.isFile()){
		  			if(image.matcher(file.getName()).matches())
		  				move(file,"Image");
		  			else if(doc.matcher(file.getName()).matches())
		  				move(file,"Docs");
		  			else if(media.matcher(file.getName()).matches())
		  				move(file,"Media");
		  			else if(code.matcher(file.getName()).matches())
		  				move(file,"Code");
		  			else
		  				move(file,"Others");
		  		}
      		}
      	}
      	catch(NullPointerException e){
      		System.out.println("No such directory exists:"+e);
      	}
      	catch(IOException e){
      		System.out.println(e);
      	}
      	catch(Exception e){
      		System.out.println(e);
      	}
 	}
}
