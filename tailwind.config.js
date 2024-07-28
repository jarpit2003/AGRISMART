/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{html,js}"], // Adjust the content paths based on your project structure
  theme: {
    extend: {
      boxShadow: {
        'cs': '0px 20px 10px rgb(0,0,0)',
      },
    },
  },
  plugins: [],
}
