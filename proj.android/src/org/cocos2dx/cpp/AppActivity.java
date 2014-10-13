/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.security.MessageDigest;

import android.app.Activity;
import android.os.Bundle;
import org.cocos2dx.lib.Cocos2dxActivity;

public class AppActivity extends Cocos2dxActivity {


	String text_file		= "text.txt" ;
	String text_zip		= "text.zip" ;

	String image_file		= "image.png" ;
	String image_zip		= "image.zip" ;

	protected void onCreate(final Bundle savedInstanceState) {

	  super.onCreate(savedInstanceState);	
	  System.out.println("------------     android System  start     ------------") ;
	  String fileName = text_file ;
  	  System.out.println("***   md5 = " + getFileMD5(fileName) + "   ***   filename = " + fileName + "   ***");

	  fileName = text_zip ;
  	  System.out.println("***   md5 = " + getFileMD5(fileName) + "   ***   filename = " + fileName + "   ***");

	  fileName = image_file ;
  	  System.out.println("***   md5 = " + getFileMD5(fileName) + "   ***   filename = " + fileName + "   ***");

	  fileName = image_zip ;
  	  System.out.println("***   md5 = " + getFileMD5(fileName) + "   ***   filename = " + fileName + "   ***");

  	  System.out.println("------------     android System  end     ------------") ;
	}
	

	  public String getFileMD5(String file) {
		  try {
			  InputStream in = this.getAssets().open(file);
		  	  MessageDigest digest = null;
//		  	  FileInputStream in = null;
		  	  byte buffer[] = new byte[1024];
		  	  int len;
		  	  try {
		  	   digest = MessageDigest.getInstance("MD5");
//		  	   in = new FileInputStream(file);
		  	   while ((len = in.read(buffer, 0, 1024)) != -1) {
		  	    digest.update(buffer, 0, len);
		  	   }
		  	   in.close();
		  	  } catch (Exception e) {
		  	   e.printStackTrace();
		  	   return null;
		  	  }
		  	  BigInteger bigInt = new BigInteger(1, digest.digest());
		  	  return bigInt.toString(16);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			return null ;
		}
	  }
		
}
