# rn-fast-image-base64

A high-performance, native implementation in C++ to convert images to base64 strings for React Native, leveraging the power of JSI.

### Why Choose rn-fast-image-base64?

- **Exceptional Speed**: Up to 10x faster than [react-native-image-base64](https://github.com/SnappFr/react-native-image-base64) on Android and approximately 1.5x faster on iOS.
- **Native Performance**: Utilizes C++ and JSI for efficient image processing.
- **Ease of Use**: Simple and straightforward API.

## Installation

Install the library using npm:

```sh
npm install rn-fast-image-base64

cd ios && pod install
```

## Usage

Import the library and use the imageToBase64 function to convert your image:

```js
import { imageToBase64 } from 'rn-fast-image-base64';

// Convert image to base64
const base64 = imageToBase64('file://yourfileurl');

```

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

This project is licensed under the MIT License.

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
