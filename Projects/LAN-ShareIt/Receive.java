import java.util.*;
import java.io.*;
import java.net.*;
class Receive {
	public static void main(String args[]) throws Exception {
		ServerSocket ss = new ServerSocket(6666);
		Socket s = ss.accept();
		InputStream in = s.getInputStream();

		int bytesRead;
		byte[] fName = new byte[1024];
		bytesRead = in.read(fName);
		String fileName = new String(fName);
		System.out.println("Receiving file : " + fileName.trim());

		FileOutputStream out = new FileOutputStream(fileName.trim());

		byte[] buffer = new byte[1024];
		while((bytesRead = in.read(buffer))!=-1) {
			out.write(buffer,0,bytesRead);
		}
		System.out.println("File Received Successfully!");
		out.close();
		in.close();
		s.close();
		ss.close();
	}
}