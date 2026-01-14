package com.example.practicals

import android.content.pm.ActivityInfo
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class Practical06ScreenOrientation : AppCompatActivity() {

    private var isPortrait = true

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical06_screen_orientation)

        val btnToggleOrientation: Button = findViewById(R.id.btnToggleOrientation)

        btnToggleOrientation.setOnClickListener {
            requestedOrientation = if (isPortrait) {
                ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE
            } else {
                ActivityInfo.SCREEN_ORIENTATION_PORTRAIT
            }
            isPortrait = !isPortrait
        }
    }
}

/*
activity_practical06_screen_orientation.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:gravity="center"
    android:orientation="vertical"
    android:padding="16dp">

    <Button
        android:id="@+id/btnToggleOrientation"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Toggle Orientation" />

</LinearLayout>
*/

