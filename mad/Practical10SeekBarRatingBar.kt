package com.example.practicals

import android.os.Bundle
import android.widget.RatingBar
import android.widget.SeekBar
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class Practical10SeekBarRatingBar : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical10_seekbar_ratingbar)

        val seekBar: SeekBar = findViewById(R.id.seekBar)
        val tvSeekValue: TextView = findViewById(R.id.tvSeekValue)
        val ratingBar: RatingBar = findViewById(R.id.ratingBar)
        val tvRatingValue: TextView = findViewById(R.id.tvRatingValue)

        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                tvSeekValue.text = "SeekBar: $progress"
            }

            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        ratingBar.setOnRatingBarChangeListener { _, rating, _ ->
            tvRatingValue.text = "Rating: $rating"
        }
    }
}

/*
activity_practical10_seekbar_ratingbar.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp">

    <SeekBar
        android:id="@+id/seekBar"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:max="100" />

    <TextView
        android:id="@+id/tvSeekValue"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="8dp"
        android:text="SeekBar: 0" />

    <RatingBar
        android:id="@+id/ratingBar"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:numStars="5"
        android:stepSize="0.5" />

    <TextView
        android:id="@+id/tvRatingValue"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="8dp"
        android:text="Rating: 0.0" />

</LinearLayout>
*/

