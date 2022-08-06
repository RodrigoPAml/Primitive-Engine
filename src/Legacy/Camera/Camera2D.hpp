#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{	
	namespace Camera
	{
		class Camera2D;
		typedef std::shared_ptr<Camera2D> Camera2DPtr;

		/// <summary>
		/// Represents a 2D camera, using orthogonal projection.
		/// </summary>
		class Camera2D
		{
		private:
			/// <summary>
			/// Camera data
			/// Camera limits (left, right, top, bottom) and znear e zfar.
			/// </summary>
			float l, r, t, b, znear, zfar;

			/// <summary>
			/// Current ortoghonal projection matrix.
			/// </summary>
			glm::mat4 orthoMatrix;

			/// <summary>
			/// Current camera used. Can be acessed globally.
			/// </summary>
			static std::weak_ptr<Camera2D> current;
		public:
			Camera2D(
				const float left = 0, 
				const float right = 800, 
				const float top = 600, 
				const float bottom = 0, 
				const float znear = 0.0f,
				const float zfar = 20.0f
			);

			glm::mat4 GetOrthoMatrix() const;

			/// <summary>
			/// Updates the current ortho matrix with current class state.
			/// </summary>
			void UpdateOrthoMatrix();

			void SetLeft(const float l);
			void SetRight(const float r);
			void SetTop(const float t);
			void SetBottom(const float b);
			void SetZNear(const float znear);
			void SetZFar(const float zfar);

			float GetLeft() const;
			float GetRight() const;
			float GetTop() const;
			float GetBottom() const;
			float GetZNear() const;
			float GetZFar() const;

			static Camera2DPtr GetCurrentCamera();
			static void SetCurrentCamera(Camera2DPtr camera);
		};
	}
}
