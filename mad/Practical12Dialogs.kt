package com.example.practicals

import android.app.AlertDialog
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class Practical12Dialogs : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical12_dialogs)

        val btnShowDialog: Button = findViewById(R.id.btnShowDialog)

        btnShowDialog.setOnClickListener {
            AlertDialog.Builder(this)
                .setTitle("Confirmation")
                .setMessage("Do you want to continue?")
                .setPositiveButton("Yes") { _, _ ->
                    Toast.makeText(this, "You clicked Yes", Toast.LENGTH_SHORT).show()
                }
                .setNegativeButton("No") { _, _ ->
                    Toast.makeText(this, "You clicked No", Toast.LENGTH_SHORT).show()
                }
                .setNeutralButton("Cancel", null)
                .show()
        }
    }
}

/*
activity_practical12_dialogs.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:gravity="center"
    android:orientation="vertical"
    android:padding="16dp">

    <Button
        android:id="@+id/btnShowDialog"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Show Dialog" />

</LinearLayout>
*/

