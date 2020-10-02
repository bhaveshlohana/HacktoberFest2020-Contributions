MainActivity.java
package com.example.a22_implicitintent_sms;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.app.PendingIntent;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
       EditText mobileno,message;
       Button sendsms;
@Override
protected void onCreate(Bundle savedInstanceState) {
       super.onCreate(savedInstanceState);
       setContentView(R.layout.activity_main);
       //this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
       mobileno=findViewById(R.id.no);
       message=findViewById(R.id.msg);
       sendsms=findViewById(R.id.sms);
       sendsms.setOnClickListener(this);
       }
@Override
public void onClick(View view) {
       String no=mobileno.getText().toString();
       String msg=message.getText().toString();
       //Getting intent and PendingIntent instance
       Intent intent=new Intent(getApplicationContext(),MainActivity.class);
       PendingIntent pi=PendingIntent.getActivity(getApplicationContext(), 0, intent,0);
       //Get the SmsManager instance and call the sendTextMessage method to send message
       SmsManager sms=SmsManager.getDefault();


       if (ContextCompat.checkSelfPermission(this,
      Manifest.permission.SEND_SMS)
      != PackageManager.PERMISSION_GRANTED) {
               // if (ActivityCompat.shouldShowRequestPermissionRationale(this,
                //       Manifest.permission.SEND_SMS)) {
         ActivityCompat.requestPermissions(this,
              new String[]{Manifest.permission.SEND_SMS},
              111);
               } else {
                       // Permission already granted
               // }
}

       sms.sendTextMessage(no, null, msg, pi,null);
       Toast.makeText(getApplicationContext(), "Message Sent successfully!",
       Toast.LENGTH_LONG).show();
       }
       }
