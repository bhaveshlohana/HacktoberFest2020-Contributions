package com.example.flashlight;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.hardware.Camera;


public class MainActivity extends AppCompatActivity {

    private Button btnSwitch;
    private Camera camera;
    private Camera.Parameters parameters;
    private boolean isFlashOn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (checkReadPermission()) {
            functionMain();
        } else {
            startActivity(new Intent(this, Permission.class));
        }
    }

    private void functionMain() {

        btnSwitch=(Button)findViewById(R.id.btnSwitch);

        btnSwitch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (isFlashOn) {
                    turnOffFlash();
                } else {
                    turnOnFlash();
                }
            }
        });

        getCamera();
        toggleImage();
    }

    private void turnOnFlash() {
        if (camera == null || parameters == null) {
            return;
        }
        parameters = camera.getParameters();
        parameters.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);
        camera.setParameters(parameters);
        camera.startPreview();
        isFlashOn = true;

        toggleImage();
    }

    private void turnOffFlash() {
        if (isFlashOn) {
            if (camera == null || parameters == null) {
                return;
            }
            parameters = camera.getParameters();
            parameters.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
            camera.setParameters(parameters);
            camera.stopPreview();
            isFlashOn = false;

            toggleImage();
        }
    }

    private void getCamera() {
        if (camera == null) {
            try {
                camera = camera.open();
                parameters = camera.getParameters();
            } catch (RuntimeException e) {

            }

        }
    }

    private void toggleImage() {
        if (isFlashOn) {
            btnSwitch.setBackgroundResource(R.drawable.on_button);
        } else {
            btnSwitch.setBackgroundResource(R.drawable.off_button);
        }
    }

    private boolean checkReadPermission() {
        int result = ActivityCompat.checkSelfPermission(getApplicationContext(), Manifest.permission.CAMERA);
        return result == PackageManager.PERMISSION_GRANTED;
    }

}
