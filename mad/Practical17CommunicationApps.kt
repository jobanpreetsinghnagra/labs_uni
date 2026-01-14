package com.example.practicals

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import androidx.appcompat.app.AppCompatActivity

class Practical17CommunicationApps : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_practical17_communication)

        val etPhone: EditText = findViewById(R.id.etPhone)
        val etEmail: EditText = findViewById(R.id.etEmail)
        val etSms: EditText = findViewById(R.id.etSms)
        val btnCall: Button = findViewById(R.id.btnCall)
        val btnEmail: Button = findViewById(R.id.btnEmail)
        val btnSms: Button = findViewById(R.id.btnSms)

        btnCall.setOnClickListener {
            val number = etPhone.text.toString()
            val intent = Intent(Intent.ACTION_DIAL, Uri.parse("tel:$number"))
            startActivity(intent)
        }

        btnEmail.setOnClickListener {
            val email = etEmail.text.toString()
            val intent = Intent(Intent.ACTION_SENDTO).apply {
                data = Uri.parse("mailto:$email")
                putExtra(Intent.EXTRA_SUBJECT, "Subject here")
            }
            startActivity(intent)
        }

        btnSms.setOnClickListener {
            val number = etPhone.text.toString()
            val message = etSms.text.toString()
            val intent = Intent(Intent.ACTION_SENDTO).apply {
                data = Uri.parse("smsto:$number")
                putExtra("sms_body", message)
            }
            startActivity(intent)
        }
    }
}

/*
activity_practical17_communication.xml

<?xml version="1.0" encoding="utf-8"?>
<ScrollView xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        android:padding="16dp">

        <EditText
            android:id="@+id/etPhone"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Phone number"
            android:inputType="phone" />

        <Button
            android:id="@+id/btnCall"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Call" />

        <EditText
            android:id="@+id/etEmail"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Email address"
            android:inputType="textEmailAddress"
            android:layout_marginTop="16dp" />

        <Button
            android:id="@+id/btnEmail"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Send Email" />

        <EditText
            android:id="@+id/etSms"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="SMS message"
            android:inputType="textMultiLine"
            android:layout_marginTop="16dp" />

        <Button
            android:id="@+id/btnSms"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Send SMS" />

    </LinearLayout>
</ScrollView>
*/

