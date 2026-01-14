package com.example.practicals

import android.os.Bundle
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical04RadioButtons : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical04_radio_buttons)

        val radioGroup: RadioGroup = findViewById(R.id.radioGroup)
        val tvSelected: TextView = findViewById(R.id.tvSelected)

        radioGroup.setOnCheckedChangeListener { group, checkedId ->
            val radioButton = group.findViewById<RadioButton>(checkedId)
            tvSelected.text = "Selected: ${radioButton.text}"
        }
    }
}

/*
activity_practical04_radio_buttons.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <RadioGroup
        android:id="@+id/radioGroup"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content">

        <RadioButton
            android:id="@+id/rbOption1"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Option 1" />

        <RadioButton
            android:id="@+id/rbOption2"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Option 2" />

        <RadioButton
            android:id="@+id/rbOption3"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Option 3" />
    </RadioGroup>

    <TextView
        android:id="@+id/tvSelected"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:paddingTop="16dp"
        android:text="Selected: " />

</LinearLayout>
*/

