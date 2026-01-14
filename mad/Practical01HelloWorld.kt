package com.example.practicals

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical01HelloWorld : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Simple Hello World using TextView in code
        val textView = TextView(this).apply {
            text = "Hello World"
            textSize = 24f
            setPadding(32, 32, 32, 32)
        }

        setContentView(textView)
    }
}

/*
Example XML layout (activity_practical01_hello_world.xml):

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:gravity="center"
    android:orientation="vertical">

    <TextView
        android:id="@+id/tvHelloWorld"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World"
        android:textSize="24sp" />

</LinearLayout>
*/

