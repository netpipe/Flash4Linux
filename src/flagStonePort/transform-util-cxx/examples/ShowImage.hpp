/*
 *  ShowImage.cpp
 *  Transform Examples
 *
 *  Created by smackay on Wed May 26 2004.
 *  Copyright (c) 2001-2004 Flagstone Software Ltd. All rights reserved.
 *
 *  This code is distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 *  EXPRESS OR IMPLIED, AND Flagstone HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING
 *  WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 *  PURPOSE, AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
 */

#ifndef __ShowImage_h__
#define __ShowImage_h__ 1

/*
 * This example shows how image can be displayed using the FSImageConstructor.
 *
 * To run this example, type the following on a command line:
 *
 *     examples --example ShowImage --file image-file [--resultDir path]
 *
 * where
 *
 *     image-file is the path to a file containing either BMP, PNG or JPEG image.
 *
 *     resultDir is the directory where the Flash file generated by the example is
 *     written to.
 *
 * The name of the Flash file generated is the same as the image file with the 
 * file extension replaced with a '.swf' suffix.
 */
class ShowImage
{
public:
	ShowImage(map< string, string>& options)
	{
		string imageFile = stringOption(options, "file");

		FSImageConstructor* imageGenerator = ImageConstructor();  
		FSMovie movie;

		int status = TransformUtil::OK;

		if ((status = imageGenerator->setImageFromFile(imageFile.c_str())) != TransformUtil::OK)
		{
			switch (status)
			{
				case TransformUtil::FileNotFound:
					cout << "Could not find sound file" << endl; break;
				case TransformUtil::ReadError:
					cout << "Could not read sound file" << endl; break;
				case TransformUtil::FormatError:
					cout << "Could not read sound file" << endl; break;
			}
		}

		if (status == TransformUtil::OK)
		{
			/* 
			* Create the FSImageConstructor object used to generate the object
			* containing the image definition. Initialize it using the name of 
			* the image file passed on the command line when the example was run.
			*/
	        
			int imageId = movie.newIdentifier();
			int shapeId = movie.newIdentifier();
	        
			int xOrigin = imageGenerator->getWidth()/2;
			int yOrigin = imageGenerator->getHeight()/2;
	        
			FSDefineObject* image = imageGenerator->defineImage(imageId);
	        
			/*
			* All images must be displayed as a bitmap fill inside a shape. The 
			* FSImageConstructor class generates the shape enclosing the image.
			* If no border is required then the line style may be set to null.
			*/
			int borderWidth = 20;
			FSColor black = FSColorTable::black();

			FSDefineShape3* shape = imageGenerator->defineShape(shapeId, imageId, 
				-xOrigin, -yOrigin, borderWidth, &black);
	        
			/* 
			* Add all the objects together to create the movie.
			*/
			movie.setFrameRate(1.0f);
			movie.setFrameSize(shape->getBounds());
			movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));
			movie.add(image);
			movie.add(shape);
			movie.add(new FSPlaceObject2(shapeId, 1, 0, 0));
			movie.add(new FSShowFrame());
	        
			saveMovie(movie, stringOption(options, "resultDir"), "ShowImage.swf");
		}
		delete imageGenerator;
	}
};

#endif

