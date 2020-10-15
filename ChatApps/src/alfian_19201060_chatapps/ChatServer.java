/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package alfian_19201060_chatapps;

import java.io.*;
import java.net.*;
import java.util.*;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

/**
 *
 * @author ALF
 */

public class ChatServer extends Application {

    Label lbLog = new Label("Log");
    Label lbUserList = new Label("-Alf-");
    
    private ArrayList<String> logList = new ArrayList<>();
    private ArrayList<String> userList = new ArrayList<>();

    ListView<String> logListView = new ListView<String>();
    ListView<String> userListView = new ListView<String>();

    ObservableList<String> logItems =
            FXCollections.observableArrayList (logList);
    ObservableList<String> userItems =
            FXCollections.observableArrayList (userList);

    private Hashtable outputStreams = new Hashtable();

    private ArrayList<Socket> socketList = new ArrayList<>();

    private ServerSocket serverSocket;

    @Override // Override the start method in the Application class
    public void start(Stage primaryStage) {

        userListView.setItems(userItems);
        logListView.setItems(logItems);
        logListView.setMinWidth(430);

        GridPane gridPane = new GridPane();
        gridPane.setPadding(new Insets(10));

        gridPane.add(lbLog,0,0);
        gridPane.add(logListView,0,1);
        gridPane.add(lbUserList,0,2);

        Scene scene = new Scene(gridPane, 450, 400);
        primaryStage.setTitle("Server"); 
        primaryStage.setScene(scene); 
        primaryStage.show(); 

        primaryStage.setOnCloseRequest(t -> closeSocketExit());

        new Thread(() -> listen()).start();
    }


    private void closeSocketExit() {
        try {
            for(Socket socket:socketList){
                if(socket!=null){
                    socket.close();
                }
            }
            Platform.exit();    
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private void listen() {
        try {
            serverSocket = new ServerSocket(9001);
            Platform.runLater(() ->
                    logItems.add("Server Dijalankan Pada " + new Date()));

            while (true) {
                Socket socket = serverSocket.accept();

                socketList.add(socket);

                Platform.runLater(() ->
                        logItems.add("Dihubungkan dari " + socket + " pada " + new Date()));

                DataOutputStream dataOutputStream =
                        new DataOutputStream(socket.getOutputStream());

                outputStreams.put(socket, dataOutputStream);

                new ServerThread(this, socket);
            }
        }
        catch(IOException ex) {
            ex.printStackTrace();
        }
    }


    private void KirimDaftarUser() {
        this.kirim(userList.toString());
    }


    Enumeration getOutputStreams(){
        return outputStreams.elements();
    }


    void kirim(String pesan){
        for (Enumeration e = getOutputStreams(); e.hasMoreElements();){
            DataOutputStream dout = (DataOutputStream)e.nextElement();
            try {
                dout.writeUTF(pesan);
            }
            catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }


    void KirimOnlineStatus(Socket socket,String pesan){
        for (Enumeration e = getOutputStreams(); e.hasMoreElements();){
            DataOutputStream dataOutputStream = (DataOutputStream)e.nextElement();
            try {
                if(!(outputStreams.get(socket) == dataOutputStream)){

                    dataOutputStream.writeUTF(pesan);
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }


    class ServerThread extends Thread {
        private ChatServer server;
        private Socket socket;
        String Nama;    
        boolean bergabung; 

        public ServerThread(ChatServer server, Socket socket) {
            this.socket = socket;
            this.server = server;
            start();
        }

        public void run() {
            try {
                DataInputStream dataInputStream =
                        new DataInputStream(socket.getInputStream());
                DataOutputStream dataOutputStream =
                        new DataOutputStream(socket.getOutputStream());

                while (true) {
                    if(!bergabung){
                        Nama = dataInputStream.readUTF();
                        if(userList.contains(Nama)){
                            dataOutputStream.writeUTF(Nama);
                        }
                        else{
                            userList.add(Nama);
                            dataOutputStream.writeUTF("Accepted");
                            server.KirimDaftarUser();
                            bergabung = true;
                            String Notifikasi = Nama + " Bergabung pada room.";
                            Platform.runLater(() ->
                                    logItems.add(Nama + " Bergabung pada room."));
                            server.KirimOnlineStatus(socket,Notifikasi);
                            userItems.clear();
                            userItems.addAll(userList);
                        }
                    }
                    else if(bergabung){
                        String string = dataInputStream.readUTF();

                        server.kirim(string);
                        server.KirimDaftarUser();

                        Platform.runLater(() ->logItems.add(string));
                    }
                }
            }



            catch(IOException ex) {
                Platform.runLater(() ->
                        logItems.add(Nama + " Terputus" ));

                if(!Nama.equals(null)){
                    userList.remove(Nama);
                }
                outputStreams.remove(socket);
                server.KirimDaftarUser();
                if (!Nama.equals(null)){
                    server.kirim(Nama + " telah meninggal.");
                }
                Platform.runLater(() ->{
                    userItems.clear();
                    userItems.addAll(userList);
                });
            }
        }
    }
        public static void main(String[] args) {
//        ChatServer clientChat = new ChatServer();
//        clientChat.jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        clientChat.jFrame.setVisible(Boolean.TRUE);
//        clientChat.run();
         Application.launch(args);
    } 
}
