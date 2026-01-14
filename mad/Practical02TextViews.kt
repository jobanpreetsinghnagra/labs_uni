package com.example.practicals

import android.os.Bundle
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical02TextViews : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical02_text_views)

        val tvLabel: TextView = findViewById(R.id.tvLabel)
        val etSingleLine: EditText = findViewById(R.id.etSingleLine)
        val etMultiline: EditText = findViewById(R.id.etMultiline)

        tvLabel.text = "Enter some text below:"

        // Simple example: show multiline text as hint based on single line input
        etSingleLine.setOnEditorActionListener { _, _, _ ->
            etMultiline.setText("You typed: ${etSingleLine.text}")
            true
        }
    }
}

/*
activity_practical02_text_views.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <TextView
        android:id="@+id/tvLabel"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Label"
        android:textSize="18sp" />

    <EditText
        android:id="@+id/etSingleLine"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="Single line text"
        android:inputType="text" />

    <EditText
        android:id="@+id/etMultiline"
        android:layout_width="match_parent"
        android:layout_height="150dp"
        android:gravity="top|start"
        android:hint="Multiline text"
        android:inputType="textMultiLine"
        android:maxLines="5" />

</LinearLayout>
*/

