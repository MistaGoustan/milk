local player = {
	speed = 2,
	flipped_x = false
 }

function player:begin()
	-- start with idle animation
	self.actor:set_animation('idle')

	-- set player as the camera target to follow
	SceneManager.current:set_cam_target(self.actor);
end

function player:update()
	if Input.get_key_pressed(Keys.F) then
		Window:toggle_fullscreen()
	end

	if Input.get_key_pressed(Keys.R) then
		SceneManager:load_scene('main_scene.json')
	end

	local inputvec = Vector2D.new(0, 0)

	if Input.get_key(Keys.W) then
		inputvec.y = -1
	end
	if Input.get_key(Keys.S) then
		inputvec.y = 1
	end
	if Input.get_key(Keys.A) then
		inputvec.x = -1

		if (not self.flipped_x) then
			self.flipped_x = true
			self.actor:flip_x()
		end
	end
	if Input.get_key(Keys.D) then
		inputvec.x = 1

		if (self.flipped_x) then
			self.flipped_x = false
			self.actor:flip_x()
		end
	end

	if (inputvec == Vector2D.new(0, 0)) then
		self.actor:set_animation('idle')
	else
		self.actor:set_animation('run')
	end

	inputvec = inputvec * self.speed

	self.actor:move(inputvec.x, inputvec.y)
end

function player:on_collision(e)
	if e.other.name == 'door' then
		SceneManager:load_scene('main_scene.json')
	end
end

function player:destroyed()
end

return player