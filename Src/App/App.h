//                       
//   _____           _   
//  |  _  |___ ___  | |_ 
//  |     | . | . |_|   |
//  |__|__|  _|  _|_|_|_|
//        |_| |_|        
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Application/DarcApplication.h"
#include "Graphics/Triangle.h"

namespace App
{
	class CApp : public DarcApplication::IDarcApplication
	{
	public:
		bool init() override;
		bool run(float secs) override;
		bool release() override;

	private:
		DarcGraphics::CTriangle* triangle;
	};
}