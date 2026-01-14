package com.example.practicals

import android.os.Bundle
import android.widget.Button
import android.widget.CheckBox
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical05CheckBoxes : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical05_checkboxes)

        val cbAndroid: CheckBox = findViewById(R.id.cbAndroid)
        val cbJava: CheckBox = findViewById(R.id.cbJava)
        val cbKotlin: CheckBox = findViewById(R.id.cbKotlin)
        val btnShow: Button = findViewById(R.id.btnShow)
        val tvResult: TextView = findViewById(R.id.tvResult)

        btnShow.setOnClickListener {
            val selected = mutableListOf<String>()
            if (cbAndroid.isChecked) selected.add("Android")
            if (cbJava.isChecked) selected.add("Java")
            if (cbKotlin.isChecked) selected.add("Kotlin")

            tvResult.text = "Selected: ${if (selected.isEmpty()) "None" else selected.joinToString()}"
        }
    }
}

/*
activity_practical05_checkboxes.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <CheckBox
        android:id="@+id/cbAndroid"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Android" />

    <CheckBox
        android:id="@+id/cbJava"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Java" />

    <CheckBox
        android:id="@+id/cbKotlin"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Kotlin" />

    <Button
        android:id="@+id/btnShow"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Show Selected" />

    <TextView
        android:id="@+id/tvResult"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:paddingTop="16dp"
        android:text="Selected: " />

</LinearLayout>
*/

