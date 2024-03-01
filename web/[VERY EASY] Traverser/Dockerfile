# Use a minimal Node.js image as the base image
FROM node:lts-alpine

# Create and set the working directory
WORKDIR /app

# Copy the package.json and package-lock.json files
COPY package*.json ./

# Install the application dependencies
RUN npm install

# Copy flag.txt to the root
COPY flag.txt /flag.txt

# Set appropriate permissions on flag.txt
RUN chmod 444 /flag.txt

# Copy the application code
COPY . .

# Remove the original flag.txt from the /app directory
RUN rm /app/flag.txt

USER node

# Expose the port on which the application will run
EXPOSE 3333

# Command to run the application
CMD ["node", "index.js"]
