package com.example.practicals

import android.os.Bundle
import android.util.Log
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical14ActivityLifecycle : AppCompatActivity() {

    private lateinit var tvLogs: TextView
    private val tag = "LifecycleDemo"

    private fun log(msg: String) {
        Log.d(tag, msg)
        tvLogs.append("$msg\n")
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical14_lifecycle)
        tvLogs = findViewById(R.id.tvLogs)
        log("onCreate")
    }

    override fun onStart() {
        super.onStart()
        log("onStart")
    }

    override fun onResume() {
        super.onResume()
        log("onResume")
    }

    override fun onPause() {
        super.onPause()
        log("onPause")
    }

    override fun onStop() {
        super.onStop()
        log("onStop")
    }

    override fun onDestroy() {
        super.onDestroy()
        // tvLogs may be null if destroyed; just logcat here
        Log.d(tag, "onDestroy")
    }
}

/*
activity_practical14_lifecycle.xml

<?xml version="1.0" encoding="utf-8"?>
<ScrollView xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <TextView
        android:id="@+id/tvLogs"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:padding="16dp"
        android:text="Lifecycle callbacks will appear here" />

</ScrollView>
*/

