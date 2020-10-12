import java.io.*;
import java.net.*;
public class Send {
	public static void main(String args[]) throws Exception {
		Socket socket = new Socket(InetAddress.getLocalHost(),6666);
		File file = new File(args[0]);
		System.out.println("Sending file: " + args[0]);

		BufferedInputStream in = new BufferedInputStream(new FileInputStream(file));
		OutputStream out = socket.getOutputStream();

		byte[] fileName = args[0].getBytes();
		out.write(fileName,0,fileName.length);
		out.flush();

		byte [] buffer = new byte[1024];
		Integer bytesRead = 0;
		while ((bytesRead = in.read(buffer)) > 0) {
			out.write(buffer);
		}
		out.write(buffer,0,buffer.length);
		System.out.println("File Sent Successfully");
		out.flush();
		out.close();
		in.close();
		socket.close();

	}
}