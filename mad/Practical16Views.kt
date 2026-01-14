package com.example.practicals

import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical16Views : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical16_views)

        val tvTitle: TextView = findViewById(R.id.tvTitle)
        val ivIcon: ImageView = findViewById(R.id.ivIcon)

        tvTitle.text = "Basic Views Example"
        // ivIcon.setImageResource(R.drawable.ic_launcher_foreground) // example
    }
}

/*
activity_practical16_views.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <TextView
        android:id="@+id/tvTitle"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Title" />

    <ImageView
        android:id="@+id/ivIcon"
        android:layout_width="100dp"
        android:layout_height="100dp"
        android:src="@mipmap/ic_launcher" />

</LinearLayout>
*/

