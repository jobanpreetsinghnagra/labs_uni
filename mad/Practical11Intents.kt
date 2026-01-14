package com.example.practicals

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import androidx.appcompat.app.AppCompatActivity

class Practical11Intents : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical11_intents)

        val etMessage: EditText = findViewById(R.id.etMessage)
        val btnSend: Button = findViewById(R.id.btnSend)

        btnSend.setOnClickListener {
            val msg = etMessage.text.toString()
            val intent = Intent(this, Practical11SecondActivity::class.java).apply {
                putExtra("message", msg)
            }
            startActivity(intent)
        }
    }
}

class Practical11SecondActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical11_second)

        val tvReceived = findViewById<android.widget.TextView>(R.id.tvReceived)
        val msg = intent.getStringExtra("message") ?: "No message"
        tvReceived.text = "Received: $msg"
    }
}

/*
activity_practical11_intents.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <EditText
        android:id="@+id/etMessage"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="Enter message" />

    <Button
        android:id="@+id/btnSend"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Send to next Activity"
        android:layout_marginTop="8dp" />

</LinearLayout>

activity_practical11_second.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:gravity="center"
    android:orientation="vertical">

    <TextView
        android:id="@+id/tvReceived"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Received:" />

</LinearLayout>
*/

