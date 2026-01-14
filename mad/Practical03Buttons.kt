package com.example.practicals

import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import android.widget.ToggleButton
import androidx.appcompat.app.AppCompatActivity

class Practical03Buttons : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical03_buttons)

        val btnClick: Button = findViewById(R.id.btnClick)
        val toggleButton: ToggleButton = findViewById(R.id.toggleButton)
        val tvStatus: TextView = findViewById(R.id.tvStatus)

        btnClick.setOnClickListener {
            tvStatus.text = "Button clicked!"
        }

        toggleButton.setOnCheckedChangeListener { _, isChecked ->
            tvStatus.text = if (isChecked) "Toggle ON" else "Toggle OFF"
        }
    }
}

/*
activity_practical03_buttons.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <Button
        android:id="@+id/btnClick"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Click Me" />

    <ToggleButton
        android:id="@+id/toggleButton"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:textOn="ON"
        android:textOff="OFF" />

    <TextView
        android:id="@+id/tvStatus"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Status will appear here"
        android:paddingTop="16dp" />

</LinearLayout>
*/

