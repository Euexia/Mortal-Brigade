#pragma once

#include "Maths/Utils.hpp"
#include "Lighting/LightShape.hpp"

namespace ltbl
{

//////////////////////////////////////////////////////////////////////////
/// \brief Light with a texture (usually all types of lights excepts sun/moon)
//////////////////////////////////////////////////////////////////////////
class LightPointEmission : public priv::QuadtreeOccupant, public priv::BaseLight, public sf::Drawable
{
	public:
		//////////////////////////////////////////////////////////////////////////
		/// \brief Ctor
		//////////////////////////////////////////////////////////////////////////
		LightPointEmission();

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the texture of the light
		/// \param texture The new texture
		//////////////////////////////////////////////////////////////////////////
		void setTexture(sf::Texture& texture);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the texture of the light
		/// \return The current texture
		//////////////////////////////////////////////////////////////////////////
		const sf::Texture* getTexture() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the texture rect of the light
		/// \param rect The new texture rect
		//////////////////////////////////////////////////////////////////////////
		void setTextureRect(const sf::IntRect& rect);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the texture rect of the light
		/// \return The current texture rect
		//////////////////////////////////////////////////////////////////////////
		const sf::IntRect& getTextureRect() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the color of the light
		/// \param color New color of the light
		//////////////////////////////////////////////////////////////////////////
		void setColor(const sf::Color& color);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the color of the light
		/// \return Color of the light
		//////////////////////////////////////////////////////////////////////////
		const sf::Color& getColor() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the combined transform of the light
		/// \return Transform combining the position/rotation/scale/origin
		//////////////////////////////////////////////////////////////////////////
		const sf::Transform& getTransform() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the position of the light
		/// \param position New position
		//////////////////////////////////////////////////////////////////////////
		void setPosition(const sf::Vector2f& position);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the position of the light
		/// \param x X coordinate of the new position
		/// \param y Y coordinate of the new position
		//////////////////////////////////////////////////////////////////////////
		void setPosition(float x, float y);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Move the light
		/// \param movement Offset
		//////////////////////////////////////////////////////////////////////////
		void move(const sf::Vector2f& movement);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Move the light
		/// \param x X offset
		/// \param y Y offset
		//////////////////////////////////////////////////////////////////////////
		void move(float x, float y);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the position of the light
		/// \return Current position
		//////////////////////////////////////////////////////////////////////////
		const sf::Vector2f& getPosition() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the rotation of the light
		/// \param angle New rotation, in degrees
		//////////////////////////////////////////////////////////////////////////
		void setRotation(float angle);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Rotate the light
		/// \param angle Angle of rotation, in degrees
		//////////////////////////////////////////////////////////////////////////
		void rotate(float angle);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the rotation of the light
		/// \return Current rotation, in degrees
		//////////////////////////////////////////////////////////////////////////
		float getRotation() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the scale of the light
		/// \param scale New scale factors
		//////////////////////////////////////////////////////////////////////////
		void setScale(const sf::Vector2f& scale);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the scale of the light
		/// \param x New horizontal scale factor
		/// \param y New vertical scale factor
		//////////////////////////////////////////////////////////////////////////
		void setScale(float x, float y);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Scale of the light
		/// \param scale Scale factors
		//////////////////////////////////////////////////////////////////////////
		void scale(const sf::Vector2f& scale);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Scale of the light
		/// \param x Horizontal scale factor
		/// \param y Vertical scale factor
		//////////////////////////////////////////////////////////////////////////
		void scale(float x, float y);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the scale of the light
		/// \return Current scale factors
		//////////////////////////////////////////////////////////////////////////
		const sf::Vector2f& getScale() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the origin of the light
		/// \param origin New origin
		//////////////////////////////////////////////////////////////////////////
		void setOrigin(const sf::Vector2f& origin);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the origin of the light
		/// \param x X coordinate of the new origin
		/// \param y Y coordinate of the new origin
		//////////////////////////////////////////////////////////////////////////
		void setOrigin(float x, float y);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the origin of the light
		/// \return Current origin
		//////////////////////////////////////////////////////////////////////////
		const sf::Vector2f& getOrigin() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Render the light
		/// \param view The current view
		/// \param lightTempTexture The light render texture
		/// \param antumbraTempTexture The antumbra render texture
		/// \param unshadowShader The unshadow shader
		/// \param lightOverShapeShader The light over shape shader
		/// \param shapes The shapes affected by the light
		//////////////////////////////////////////////////////////////////////////
		void render(const sf::View& view,
			sf::RenderTexture& lightTempTexture, sf::RenderTexture& antumbraTempTexture, sf::RenderTexture& specularTexture,
			sf::Shader& unshadowShader, sf::Shader& lightOverShapeShader,
			const std::vector<priv::QuadtreeOccupant*>& shapes,
			bool normalsEnabled, sf::Shader& normalsShader, sf::Shader& specularShader, sf::RenderTexture& emissionTempTexture, sf::RenderTexture& emissionTempSpecTexture);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the local cast center of the light
		/// \param localCenter The new local cast center
		//////////////////////////////////////////////////////////////////////////
		void setLocalCastCenter(const sf::Vector2f& localCenter);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the local cast center of the light
		/// \return The current local cast center
		//////////////////////////////////////////////////////////////////////////
		sf::Vector2f getLocalCastCenter() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the source radius
		/// \param radius The new source radius
		//////////////////////////////////////////////////////////////////////////
		void setSourceRadius(float radius);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the source radius
		/// \return The current source radius
		//////////////////////////////////////////////////////////////////////////
		float getSourceRadius() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Set the shadow over extend multiplier
		/// \param multiplier The new shadow over extend multiplier
		//////////////////////////////////////////////////////////////////////////
		void setShadowOverExtendMultiplier(float multiplier);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the shadow over extend multiplier
		/// \return The current shadow over extend multiplier
		//////////////////////////////////////////////////////////////////////////
		float getShadowOverExtendMultiplier() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the AABB box of the light
		/// \return The AABB box
		//////////////////////////////////////////////////////////////////////////
		sf::FloatRect getAABB() const override;

		float getZPosition() const;

		void setZPosition(const float z_pos);

	private:
		//////////////////////////////////////////////////////////////////////////
		/// \brief Get the cast center of the light
		/// \return The current cast center
		//////////////////////////////////////////////////////////////////////////
		sf::Vector2f getCastCenter() const;

		//////////////////////////////////////////////////////////////////////////
		/// \brief Get penumbras point from a point
		/// \param penumbras The penumbras
		/// \param innerBoundaryIndices The inner boundary indices
		/// \param innerBoundaryVectors The inner boundary vectors
		/// \param outerBoundaryIndices The outer boundary indices
		/// \param outerBoundaryVectors The outer boundary vectors
		/// \param shape The shape
		//////////////////////////////////////////////////////////////////////////
		void getPenumbrasPoint(std::vector<priv::Penumbra>& penumbras, std::vector<int>& innerBoundaryIndices, std::vector<sf::Vector2f>& innerBoundaryVectors, std::vector<int>& outerBoundaryIndices, std::vector<sf::Vector2f>& outerBoundaryVectors, const LightShape& shape);

		//////////////////////////////////////////////////////////////////////////
		/// \brief Draw the light
		/// \param target The render target to apply the light on
		/// \param states The render states to apply to the light on render
		//////////////////////////////////////////////////////////////////////////
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::Sprite mSprite; ///< The sprite of the light

		sf::Vector2f mLocalCastCenter; ///< The local cast center

		float mSourceRadius; ///< The source radius

		float mShadowOverExtendMultiplier; ///< The shadow over extend multiplier

		float mZPosition;

		sf::ConvexShape mask_shape_;
		std::vector<bool> facingFrontBothEdges;
		std::vector<bool> facingFrontOneEdge;
};

} // namespace ltbl
